<?php
/**
 * @file
 * default_panels.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function default_panels_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
$handler->api_version = 1;
$handler->name = 'site_template_panel_context_4';
$handler->task = 'site_template';
$handler->subtask = '';
$handler->handler = 'panel_context';
$handler->weight = 3;
$handler->conf = array(
  'title' => 'Sitewide Panels',
  'no_blocks' => 1,
  'pipeline' => 'standard',
  'body_classes_to_remove' => '',
  'body_classes_to_add' => '',
  'css_id' => '',
  'css' => '',
  'contexts' => array(),
  'relationships' => array(),
  'access' => array(
    'plugins' => array(),
    'logic' => 'and',
  ),
);
$display = new panels_display();
$display->layout = 'onecol';
$display->layout_settings = array();
$display->panel_settings = array(
  'style_settings' => array(
    'default' => NULL,
    'middle' => NULL,
  ),
);
$display->cache = array();
$display->title = '';
$display->uuid = 'b6c2009a-15e9-4583-9b2a-7a46ddc7f93a';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-f4dc89f6-1b5c-449c-a6f7-933147c83c4f';
  $pane->panel = 'middle';
  $pane->type = 'page_title';
  $pane->subtype = 'page_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'markup' => 'h1',
    'class' => '',
    'id' => '',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f4dc89f6-1b5c-449c-a6f7-933147c83c4f';
  $display->content['new-f4dc89f6-1b5c-449c-a6f7-933147c83c4f'] = $pane;
  $display->panels['middle'][0] = 'new-f4dc89f6-1b5c-449c-a6f7-933147c83c4f';
  $pane = new stdClass();
  $pane->pid = 'new-7188f4f3-993f-482f-ad43-978efa31ac40';
  $pane->panel = 'middle';
  $pane->type = 'pane_messages';
  $pane->subtype = 'pane_messages';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '7188f4f3-993f-482f-ad43-978efa31ac40';
  $display->content['new-7188f4f3-993f-482f-ad43-978efa31ac40'] = $pane;
  $display->panels['middle'][1] = 'new-7188f4f3-993f-482f-ad43-978efa31ac40';
  $pane = new stdClass();
  $pane->pid = 'new-35465aae-eec5-4b66-a6b8-6095e2000abe';
  $pane->panel = 'middle';
  $pane->type = 'page_content';
  $pane->subtype = 'page_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_page_content_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '35465aae-eec5-4b66-a6b8-6095e2000abe';
  $display->content['new-35465aae-eec5-4b66-a6b8-6095e2000abe'] = $pane;
  $display->panels['middle'][2] = 'new-35465aae-eec5-4b66-a6b8-6095e2000abe';
$display->hide_title = PANELS_TITLE_NONE;
$display->title_pane = 'new-35465aae-eec5-4b66-a6b8-6095e2000abe';
$handler->conf['display'] = $display;

  $export['site_template_panel_context'] = $handler;
    

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function default_panels_default_page_manager_pages() {
  $page = new stdClass();
$page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
$page->api_version = 1;
$page->name = 'homepage';
$page->task = 'page';
$page->admin_title = 'Homepage';
$page->admin_description = '';
$page->path = 'home';
variable_set('site_frontpage', 'home');
$page->access = array(
  'plugins' => array(
    0 => array(
      'name' => 'front',
      'settings' => NULL,
      'not' => FALSE,
    ),
  ),
  'logic' => 'and',
);
$page->menu = array();
$page->arguments = array();
$page->conf = array(
  'admin_paths' => FALSE,
);
$page->default_handlers = array();
$handler = new stdClass();
$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
$handler->api_version = 1;
$handler->name = 'page_homepage_panel_context';
$handler->task = 'page';
$handler->subtask = 'homepage';
$handler->handler = 'panel_context';
$handler->weight = 0;
$handler->conf = array(
  'title' => 'Panel',
  'no_blocks' => 1,
  'pipeline' => 'ipe',
  'body_classes_to_remove' => '',
  'body_classes_to_add' => '',
  'css_id' => '',
  'css' => '',
  'contexts' => array(),
  'relationships' => array(),
  'access' => array(
    'plugins' => array(),
    'logic' => 'and',
  ),
  'panels_everywhere_site_template' => '-1',
);
$display = new panels_display();
$display->layout = 'clooney_one';
$display->layout_settings = array();
$display->panel_settings = array(
  'style_settings' => array(
    'default' => NULL,
    'header' => NULL,
    'middle' => NULL,
    'footer' => NULL,
  ),
);
$display->cache = array();
$display->title = '';
$display->uuid = '685da809-8e13-4bcd-9171-d8c11a7c0301';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-3fd199b1-d319-4fec-a773-c15d89e17660';
  $pane->panel = 'middle';
  $pane->type = 'herocloon_custom_pane';
  $pane->subtype = 'herocloon_custom_pane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'bgimage' => 0,
    'bgfixed' => 1,
    'bgcolor' => '#000',
    'textcolor' => '#fff',
    'fullheight' => 0,
    'scrolldown' => 0,
    'title' => 'Clooney',
    'body' => array(
      'value' => 'Your hero.',
      'format' => 'full_html',
    ),
    'cssclass' => '',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '3fd199b1-d319-4fec-a773-c15d89e17660';
  $display->content['new-3fd199b1-d319-4fec-a773-c15d89e17660'] = $pane;
  $display->panels['middle'][0] = 'new-3fd199b1-d319-4fec-a773-c15d89e17660';
$display->hide_title = PANELS_TITLE_NONE;
$display->title_pane = '0';
$handler->conf['display'] = $display;
$page->default_handlers[$handler->name] = $handler;

  $pages['homepage'] = $page;

  return $pages;

}
