<?php

$plugin = array(
  'single' => TRUE,  // Just do this one, it is needed.
  'title' => t('Signup Cloon'),  // Title to show up on the pane screen.
  'description' => t('Newsletter signup'), // Description to show up on the pane screen.
  'category' => t('CLOONEY'), // A category to put this under.
  'edit form' => 'signupcloon_pane_custom_pane_edit_form', // A function that will return the settings form for the pane.
  'render callback' => 'signupcloon_pane_custom_pane_render', // A function that will return the renderable content.
  'admin info' => 'signupcloon_pane_custom_pane_admin_info', // A function that will return the information displayed on the admin screen (optional).
  'defaults' => array( // Array of defaults for the settings form.
    
    'theform' => '',
    'already_check' => '',
    'invalid_check' => '',
    'thankyou' => ''

  ),
  'all contexts' => TRUE, // This is NEEDED to be able to use substitution strings in your pane.
);

/**
 * An edit form for the pane's settings.
 */
function signupcloon_pane_custom_pane_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['theform'] = array(
    '#type' => 'textarea',
    '#format' => 'php',
    '#title' => 'Signup Form Code',
    '#default_value' => $conf['theform'],
    '#description' => 'The form will be submitted via cURL to the form action. HTML allowed.'
  );
  $form['invalid_check'] = array(
    '#type' => 'textfield',
    '#title' => t('Invalid Check'),
    '#description' => t('Enter some unique text that the signup page would have indicating that an invalid email address was entered. For example, "There are errors below" for MailChimp forms.'),
    '#default_value' => $conf['invalid_check']
  );
  $form['already_check'] = array(
    '#type' => 'textfield',
    '#title' => t('Already Signed Up Check'),
    '#description' => t('Enter some unique text that the signup page would have indicating that an already-registered email address was entered. For example, "is already subscribed" for MailChimp forms.'),
    '#default_value' => $conf['already_check']
  );
  $form['thankyou'] = array(
    '#type' => 'textfield',
    '#title' => t('Thank You Message'),
    '#description' => t('The form will be replaced with this message upon completion.'),
    '#default_value' => $conf['thankyou']
  );
  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function signupcloon_pane_custom_pane_edit_form_submit(&$form, &$form_state) {

  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
  
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function signupcloon_pane_custom_pane_render($subtype, $conf, $args, $contexts) {
 
  // Update the strings to allow contexts.
  /*if (!empty($contexts)) {
    $content = ctools_context_keyword_substitute($conf['text'], array(), $contexts);
  }*/

  $content = theme('signupcloon_signup', $conf);

  $block = new stdClass();
 
  // initial content is blank
  $block->title = ''; // This will be overridden by the user within the panel options.
  $block->content = $content;
 
  return $block;
}