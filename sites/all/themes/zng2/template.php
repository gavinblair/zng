<?php

function zng2_form_alter(&$form, &$form_state, $form_id){
  if($form_id == 'user_register_form') {
    $form['account']['mail']['#description'] = t("We won't sell your information, we promise!");
  }
}