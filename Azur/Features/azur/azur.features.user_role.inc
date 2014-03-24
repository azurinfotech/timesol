<?php
/**
 * @file
 * azur.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function azur_user_default_roles() {
  $roles = array();

  // Exported role: Intranet Admin.
  $roles['Intranet Admin'] = array(
    'name' => 'Intranet Admin',
    'weight' => '2',
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => '3',
  );

  return $roles;
}
