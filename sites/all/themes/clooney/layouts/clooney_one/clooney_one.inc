<?php

/**
 * implementation of hook_panels_layouts()
 */
// Plugin definition
$plugin = array(
  'title' => t('Single column layout for Clooney'),
  'category' => t('Columns: 1'),
  'icon' => 'clooney_one.png',
  'theme' => 'clooney_one',
  'css' => 'clooney_one.css',
  'regions' => array(
  	'header' => t('Header'),
  	'middle' => t('Middle'),
  	'footer' => t('Footer')
  ),
);
