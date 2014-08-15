<?php

$plugin = array(
  'single' => TRUE,  // Just do this one, it is needed.
  'title' => t('Emergency Bar'),  // Title to show up on the pane screen.
  'description' => t('Provide an emergency banner panel.'), // Description to show up on the pane screen.
  'category' => t('CLOONEY'), // A category to put this under.
  //'edit form' => 'emergency_pane_custom_pane_edit_form', // A function that will return the settings form for the pane.
  'render callback' => 'emergency_pane_custom_pane_render', // A function that will return the renderable content.
  //'admin info' => 'emergency_pane_custom_pane_admin_info', // A function that will return the information displayed on the admin screen (optional).
  'defaults' => array( // Array of defaults for the settings form.


  ),
  'all contexts' => TRUE, // This is NEEDED to be able to use substitution strings in your pane.
);


/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function emergency_pane_custom_pane_render($subtype, $conf, $args, $contexts) {
  $ec = variable_get('emergency_content', '');
  $content = theme('emergency_panel', array('content' => isset($ec['value']) ? check_markup($ec['value'], $ec['format']) : ''));

  $block = new stdClass();
 
  // initial content is blank
  $block->title = ''; // This will be overridden by the user within the panel options.
  $block->content = $content;
 
  return $block;
}