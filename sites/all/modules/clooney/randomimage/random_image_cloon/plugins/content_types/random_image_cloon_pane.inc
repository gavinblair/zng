<?php

$plugin = array(
    'single' => TRUE, // Just do this one, it is needed.
    'title' => t('Random Image Cloon'), // Title to show up on the pane screen.
    'description' => t('Similar to the Hero Cloon, except will display a random image.'), // Description to show up on the pane screen.
    'category' => t('CLOONEY'), // A category to put this under.
    'edit form' => 'random_image_cloon_pane_custom_pane_edit_form', // A function that will return the settings form for the pane.
    'render callback' => 'random_image_cloon_pane_custom_pane_render', // A function that will return the renderable content.
    'admin info' => 'random_image_cloon_pane_custom_pane_admin_info', // A function that will return the information displayed on the admin screen (optional).
    'defaults' => array(// Array of defaults for the settings form.
	'bgfixed' => true,
	'bgcolor' => '#000',
	'textcolor' => '#fff',
	'fullheight' => false,
	'scrolldown' => false,
	'title' => '',
	'body' => '',
	'cssclass' => '',
	'height' => '',
	'allow_dupes' => false,
	'body_format' => 'full_html'
    ),
    'all contexts' => TRUE, // This is NEEDED to be able to use substitution strings in your pane.
);

/**
 * An edit form for the pane's settings.
 */
function random_image_cloon_pane_custom_pane_edit_form($form, &$form_state) {
    $conf = $form_state['conf'];
    
    $form['bgfixed'] = array(
	'#type' => 'checkbox',
	'#title' => t('Fixed Background'),
	'#description' => t('Should the background image stay fixed when the user scrolls?'),
	'#default_value' => $conf['bgfixed']
    );

    $form['bgcolor'] = array(
	'#type' => 'textfield',
	'#title' => t('Background Colour'),
	'#description' => t('Hex value of the desired background colour.'),
	'#default_value' => $conf['bgcolor']
    );
    $form['textcolor'] = array(
	'#type' => 'textfield',
	'#title' => t('Text Colour'),
	'#description' => t('Hex value of the desired text colour.'),
	'#default_value' => $conf['textcolor']
    );

    $form['fullheight'] = array(
	'#type' => 'checkbox',
	'#title' => t('Full Height'),
	'#description' => t('Should this section be the full height of the browser?'),
	'#default_value' => $conf['fullheight']
    );

    $form['height'] = array(
	'#type' => 'textfield',
	'#title' => t('Height Of The Pane'),
	'#description' => t('Use either full height or this field, using both will result in weird behaviour'),
	'#default_value' => $conf['height'],
    );

    $form['scrolldown'] = array(
	'#type' => 'checkbox',
	'#title' => t('Scroll Down Button'),
	'#description' => t('Should a Scroll Down button be provided?'),
	'#default_value' => $conf['scrolldown']
    );

    $form['allow_dupes'] = array(
	'#type' => 'checkbox',
	'#title' => t('Allow Dupes'),
	'#description' => t('Should duplicate images be allowed on the same panel page?'),
	'#default_value' => $conf['allow_dupes']
    );

    $form['title'] = array(
	'#type' => 'textfield',
	'#title' => t('Big Text'),
	'#description' => t(''),
	'#default_value' => $conf['title']
    );

    $form['body'] = array(
	'#type' => 'text_format',
	'#title' => t('Body'),
	'#default_value' => $conf['body'],
	'#format' => $conf['body_format'],
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
 * The submit form stores the data in $conf.
 */
function random_image_cloon_pane_custom_pane_edit_form_submit($form, &$form_state) {
    // have to store the body format in the form values so that the correct format can be displayed later
    $form_state['values']['body_format'] = $form_state['values']['body']['format'];
    
    $form_state['values']['body'] = $form_state['values']['body']['value'];

    // Otherwise, just save values into $conf normally.

    foreach (array_keys($form_state['plugin']['defaults']) as $key) {
	$form_state['conf'][$key] = isset($form_state['values'][$key]) ? $form_state['values'][$key] : $form_state['plugin']['defaults'][$key];
    }
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function random_image_cloon_pane_custom_pane_render($subtype, $conf, $args, $contexts) {

    // Update the strings to allow contexts.
    if (!empty($contexts)) {
	foreach ($conf as $c => $v) {
	    if (is_string($v)) {
		$conf[$c] = ctools_context_keyword_substitute($v, array(), $contexts);
	    }
	}
    }
    
    // at render time, we check the markup to make sure it is good
    $conf['body'] = check_markup($conf['body'], $conf['body_format']);

    $conf['bgimage'] = random_image_cloon_get_image((bool) $conf['allow_dupes']);

    $content = theme('random_image_cloon', $conf);

    $block = new stdClass();

    // initial content is blank
    $block->title = ''; // This will be overridden by the user within the panel options.
    $block->content = $content;

    return $block;
}

/**
 * Get a random image from the images that have been saved
 * @staticvar array $used stores previous results
 * @param boolean $allow_dupes whether or not to allow duplicate images
 * @return int the fid
 */
function random_image_cloon_get_image($allow_dupes = false) {
    static $used = array();
    if ($used) {
	$result = views_get_view_result('random_image_cloon_view', 'block', implode(',', $used));
    } else {
	$result = views_get_view_result('random_image_cloon_view', 'block');
    }
    $return = $result[0]->_field_data['nid']['entity']->field_photo[LANGUAGE_NONE][0]['fid'];
    // exclude this from the next panel view on this page
    if (!$allow_dupes) {
	$used[] = $result[0]->nid;
    }
    return $return;
}