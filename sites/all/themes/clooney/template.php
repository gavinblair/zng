<?php

function clooney_preprocess_html(&$vars) {
	// jquery.cookie plugin is not being loaded for anonymous users
  // causing all jQuery and Javascript to break on the site.	
  drupal_add_library('system', 'jquery.cookie');
  
  $vars['classes_array'][] = 'clooney';

  // Setup IE meta tag to force IE rendering mode
  $meta_ie_render_engine = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'content' =>  'IE=edge,chrome=1',
      'http-equiv' => 'X-UA-Compatible',
    )
  );
  $HandheldFriendly = array(
  	'#type' => 'html_tag',
  	'#tag' => 'meta',
  	'#attributes' => array(
  		'name' => 'HandheldFriendly',
  		'content' => 'True'
  	)
  );
  $MobileOptimized = array(
  	'#type' => 'html_tag',
  	'#tag' => 'meta',
  	'#attributes' => array(
  		'name' => 'MobileOptimized',
  		'content' => '320'
  	)
  );
  $viewport = array(
  	'#type' => 'html_tag',
  	'#tag' => 'meta',
  	'#attributes' => array(
  		'name' => 'viewport',
  		'content' => 'width=device-width, initial-scale=1, minimal-ui'
  	)
  );

  
  // Add header meta tag for IE to head
  drupal_add_html_head($meta_ie_render_engine, 'meta_ie_render_engine');
  drupal_add_html_head($HandheldFriendly, 'HandheldFriendly');
  drupal_add_html_head($MobileOptimized, 'MobileOptimized');
  drupal_add_html_head($viewport, 'viewport');
  // add the bootstrap css to the page even if there isn't a hero on it
  drupal_add_css(drupal_get_path('theme', 'clooney') . '/css/clooney.css', array('group' => CSS_DEFAULT, 'every_page' => TRUE));
  drupal_add_js(drupal_get_path('theme', 'clooney') . '/js/modernizr.js', array('group' => CSS_DEFAULT, 'every_page' => TRUE));
}
