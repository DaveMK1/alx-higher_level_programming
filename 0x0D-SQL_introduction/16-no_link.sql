-- select all entries with a nameSELECT `score`, `name`
FROM `second_table`
WHERE `name` != ""
ORDER BY `score` DESC
