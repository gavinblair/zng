<?php

$plugin = array(
  'single' => TRUE,  // Just do this one, it is needed.
  'title' => t('Grid Cloon'),  // Title to show up on the pane screen.
  'description' => t('Display a view as a grid.'), // Description to show up on the pane screen.
  'category' => t('CLOONEY'), // A category to put this under.
  'edit form' => 'gridcloon_pane_custom_pane_edit_form', // A function that will return the settings form for the pane.
  'render callback' => 'gridcloon_pane_custom_pane_render', // A function that will return the renderable content.
  'admin info' => 'gridcloon_pane_custom_pane_admin_info', // A function that will return the information displayed on the admin screen (optional).
  'defaults' => array( // Array of defaults for the settings form.
    
    'cssclass' => '',
    'block' => '',
    'grid' => ''




  ),
  'all contexts' => TRUE, // This is NEEDED to be able to use substitution strings in your pane.
);

/**
 * An edit form for the pane's settings.
 */
function gridcloon_pane_custom_pane_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  //todo - make it so you choose a view or block here
  $sql = "SELECT delta FROM block WHERE module = 'views' AND theme = 'clooney'";
  $results = db_query($sql)->fetchAll();
  $blocks = array();
  foreach($results as $result){
    $blocks[$result->delta] = $result->delta;
  }

  $form['grid'] = array(
    '#type' => 'select',
    '#title' => t('Grid to use'),
    '#description' => t('Choose which grid to use.'),
    '#default_value' => $conf['grid'],
    '#options' => array(
      'col-1-2' => '2 Columns',
      'col-1-3' => '3 Columns',
      'col-1-4' => '4 Columns'
    )
  );
  $form['block'] = array(
    '#type' => 'select',
    '#title' => t('Block to use'),
    '#description' => t('Choose a block view that will be outputted as a grid'),
    '#default_value' => $conf['block'],
    '#options' => $blocks
  );

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
function gridcloon_pane_custom_pane_edit_form_submit(&$form, &$form_state) {

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
function gridcloon_pane_custom_pane_render($subtype, $conf, $args, $contexts) {
 
  // Update the strings to allow contexts.
  /*if (!empty($contexts)) {
    $content = ctools_context_keyword_substitute($conf['text'], array(), $contexts);
  }*/

  $content = theme('gridcloon_grid', $conf);

  $block = new stdClass();
 
  // initial content is blank
  $block->title = ''; // This will be overridden by the user within the panel options.
  $block->content = $content;
 
  return $block;
}