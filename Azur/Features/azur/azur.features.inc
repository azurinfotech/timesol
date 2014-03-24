<?php
/**
 * @file
 * azur.features.inc
 */

/**
 * Implements hook_views_api().
 */
function azur_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function azur_node_info() {
  $items = array(
    'carousel' => array(
      'name' => t('Carousel'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'departments' => array(
      'name' => t('Departments'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
