<?php
/**
 * @file
 * manager_role.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function manager_role_user_default_roles() {
  $roles = array();

  // Exported role: manager.
  $roles['manager'] = array(
    'name' => 'manager',
    'weight' => 3,
  );

  return $roles;
}
