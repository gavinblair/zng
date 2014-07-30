<?php

$plugin = array(
  'single' => TRUE,  // Just do this one, it is needed.
  'title' => t('Case Studies Cloon'),  // Title to show up on the pane screen.
  'description' => t('A slider of articles.'), // Description to show up on the pane screen.
  'category' => t('CLOONEY'), // A category to put this under.
  'edit form' => 'casestudiescloon_pane_custom_pane_edit_form', // A function that will return the settings form for the pane.
  'render callback' => 'casestudiescloon_pane_custom_pane_render', // A function that will return the renderable content.
  'admin info' => 'casestudiescloon_pane_custom_pane_admin_info', // A function that will return the information displayed on the admin screen (optional).
  'defaults' => array( // Array of defaults for the settings form.
    
    'cssclass' => ''





  ),
  'all contexts' => TRUE, // This is NEEDED to be able to use substitution strings in your pane.
);

/**
 * An edit form for the pane's settings.
 */
function casestudiescloon_pane_custom_pane_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  //view? block?

  $form['cssclass'] = array(
    '#type' => 'textfield',
    '#title' => t('CSS Class'),
    '#description' => t('Add a California Style Sheets class in order to set this panel apart from the others.'),
    '#default_value' => $conf['cssclass']
  );
  return $form;
}
 
/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function casestudiescloon_pane_custom_pane_edit_form_submit(&$form, &$form_state) {

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
function casestudiescloon_pane_custom_pane_render($subtype, $conf, $args, $contexts) {
 
  // Update the strings to allow contexts.
  /*if (!empty($contexts)) {
    $content = ctools_context_keyword_substitute($conf['text'], array(), $contexts);
  }*/

  $content = theme('casestudiescloon_casestudies', $conf);

  $block = new stdClass();
 
  // initial content is blank
  $block->title = ''; // This will be overridden by the user within the panel options.
  $block->content = $content;
 
  return $block;
}