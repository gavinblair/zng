<?php /**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<ul class='casectrl'>
    <?php $c = 0; foreach ($rows as $id => $row): ?>
        <li><a class="<?php echo $c === 0 ? 'active' : ''; ?>" data-slide-index="<?php echo $id; ?>"></a></li>
    <?php $c++; endforeach; ?>
</ul>
<ul class="caseslider">
<?php foreach ($rows as $id => $row): ?>
    <li>
        <section>
            <div class="holder" data-slide-index="<?php echo $id; ?>">
                <?php print $row; ?>
            </div>
        </section>
    </li>
<?php endforeach; ?>
</ul>
        