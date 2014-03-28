<div class="my-progress"><?php print drupal_render($form['progress']) ?></div>
<table class="form-table" style="border:1px solid; padding:20px; box-shadow:-5px 5px 5px 5px #CCC">
  <tbody>
    <tr style="margin-left:20px;margin-right: 20px;"><td width="35%" style="vertical-align: top; padding: 20px;"><?php print drupal_render($form['help_text']); ?></td>
    	<td style="padding: 20px;"><?php print drupal_render_children($form); ?></td></tr>
    </tbody>
</table>
<?php print drupal_render_children($form); ?>