<table class="form-table">
  <tbody>
    <tr><td ><?php print drupal_render($form['adid']); ?></td></tr>
  	<tr><td><?php print drupal_render($form['fid']); ?></td></tr>
    <tr><td><?php print drupal_render($form['rtype']); ?></td></tr>
    </tbody>
</table>
<?php print drupal_render_children($form); ?>