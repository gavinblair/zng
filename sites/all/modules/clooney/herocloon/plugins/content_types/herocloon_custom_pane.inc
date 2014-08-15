<?php

$plugin = array(
    'single' => TRUE, // Just do this one, it is needed.
    'title' => t('Hero Cloon'), // Title to show up on the pane screen.
    'description' => t('The man. The legend. The HERO.'), // Description to show up on the pane screen.
    'category' => t('CLOONEY'), // A category to put this under.
    'edit form' => 'herocloon_pane_custom_pane_edit_form', // A function that will return the settings form for the pane.
    'render callback' => 'herocloon_pane_custom_pane_render', // A function that will return the renderable content.
    'admin info' => 'herocloon_pane_custom_pane_admin_info', // A function that will return the information displayed on the admin screen (optional).
    'icon' => 'emblem.png',
    'defaults' => array(// Array of defaults for the settings form.
	'bgimage' => false,
	'overlay' => false,
	'bgfixed' => true,
	'bgcolor' => '#000',
	'textcolor' => '#fff',
	'fullheight' => false,
	'scrolldown' => false,
	'title' => '',
	'body' => '',
	'cssclass' => '',
    ),
    'all contexts' => TRUE, // This is NEEDED to be able to use substitution strings in your pane.
);

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function herocloon_pane_custom_pane_render($subtype, $conf, $args, $contexts) {

    // Update the strings to allow contexts.
    if (!empty($contexts)) {
	foreach ($conf as $c => $v) {
	    if (is_string($v)) {
		$conf[$c] = ctools_context_keyword_substitute($v, array(), $contexts);
	    }
	}
    }
    
    $conf['body'] = check_markup($conf['body']['value'], $conf['body']['format']);

    $content = theme('herocloon_hero', $conf);

    $block = new stdClass();

    // initial content is blank
    $block->title = ''; // This will be overridden by the user within the panel options.
    $block->content = $content;

    return $block;
}

function herocloon_pane_custom_pane_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : '';
    
    $conf['body'] = check_markup($conf['body']['value'], $conf['body']['format']);

    $block->content = theme('herocloon_hero', $conf);
    
    return $block;
  }
}