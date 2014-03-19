<fieldset class="panel panel-default form-wrapper">
<legend class="panel-heading">
<div class="panel-title fieldset-ledgend"></div></ledgend>
<table class="form-table">
  <tbody>
    <?php $i= 0;
    foreach($form as $key => $value){
    if(is_array($value)){if(isset($value['#type'])&& $value['#type'] != 'submit' && $value['#type'] != 'hidden'){
    if($i%2 == 0){?>
    <tr>
    <?php } ?>
    <td><?php print(drupal_render($form[$key])); ?></td>
    <?php if($i%2 ==1){ ?>
    </tr>
   <?php }}} $i++; }?>
  </tbody>
</table>
</fieldset>
<?php print drupal_render_children($form); ?>