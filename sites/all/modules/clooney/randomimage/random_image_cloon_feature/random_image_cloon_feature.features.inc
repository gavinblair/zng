<?php
/**
 * @file
 * random_image_cloon_feature.features.inc
 */

/**
 * Implements hook_views_api().
 */
function random_image_cloon_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function random_image_cloon_feature_node_info() {
  $items = array(
    'header_photos' => array(
      'name' => t('Random Photos'),
      'base' => 'node_content',
      'description' => 'Holds the photos that will be displayed in the random photo panels',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
