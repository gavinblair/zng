<?php

$plugin = array(
    'single' => TRUE, // Just do this one, it is needed.
    'title' => t('Menu Cloon'), // Title to show up on the pane screen.
    'description' => t('The Menu'), // Description to show up on the pane screen.
    'category' => t('CLOONEY'), // A category to put this under.
    'edit form' => 'menucloon_pane_custom_pane_edit_form', // A function that will return the settings form for the pane.
    'render callback' => 'menucloon_pane_custom_pane_render', // A function that will return the renderable content.
    'admin info' => 'menucloon_pane_custom_pane_admin_info', // A function that will return the information displayed on the admin screen (optional).
    'defaults' => array(// Array of defaults for the settings form.
	'sticky' => false,
	'style' => 'slide',
	'topcontent' => '',
	'sidebarcontent' => '',
	'navbar_position' => 'navbar-right',
    ),
    'all contexts' => TRUE, // This is NEEDED to be able to use substitution strings in your pane.
);

/**
 * An edit form for the pane's settings.
 */
function menucloon_pane_custom_pane_edit_form($form, &$form_state) {
    $conf = $form_state['conf'];

    $form['sticky'] = array(
	'#type' => 'checkbox',
	'#title' => t('Sticky Menu'),
	'#description' => t('Should the menu be fixed to the top of the browser when the user scrolls down?'),
	'#default_value' => $conf['sticky']
    );
    $form['style'] = array(
	'#type' => 'select',
	'#options' => array(
	    'top' => 'Top Menu',
	    'slide' => 'Hamburger: Slide',
	    'collapse-to-hamburger' => 'Collapse to Hamburger',
	    'menu-cloon-drawer' => 'Hamburger with drawer underneath',
	),
	'#title' => 'Menu Style',
	'#description' => 'Choose the menu style and effect.',
	'#default_value' => $conf['style']
    );
    
    $form['navbar_position'] = array(
	'#type' => 'select',
	'#options' => array(
	    'navbar-right' => 'Right',
	    'navbar-left' => 'Left',
	    'navbar-center' => 'Center',
	),
	'#title' => 'Navbar Position',
	'#description' => 'Only affects position of the menu when Collapse to Hamburger or Top Menu are selected.',
	'#default_value' => $conf['navbar_position']
    );
    
    $form['topcontent'] = array(
	'#type' => 'textarea',
	'#title' => 'Additional Content at the Top',
	'#description' => '',
	'#default_value' => $conf['topcontent']
    );
    $form['sidebarcontent'] = array(
	'#type' => 'textarea',
	'#title' => 'Additional Content in the Sidebar',
	'#description' => '',
	'#default_value' => $conf['sidebarcontent']
    );


    return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function menucloon_pane_custom_pane_edit_form_submit(&$form, &$form_state) {
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
function menucloon_pane_custom_pane_render($subtype, $conf, $args, $contexts) {

    // Update the strings to allow contexts.
    /* if (!empty($contexts)) {
      $content = ctools_context_keyword_substitute($conf['text'], array(), $contexts);
      } */
    
    $content = theme('menucloon_menu', $conf);

    $block = new stdClass();

    // initial content is blank
    $block->title = ''; // This will be overridden by the user within the panel options.
    $block->content = $content;

    return $block;
}
