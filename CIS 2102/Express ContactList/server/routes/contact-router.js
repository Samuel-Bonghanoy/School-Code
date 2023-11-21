const express = require('express');

const connection = require('../db');

const router = express.Router({ mergeParams: true });

router.post('/addPerson', (req, res) => {
  try {
    const { name, age, id, course } = req.body;

    connection.query(
      'INSERT INTO persons (id, name, age, course) VALUES (?, ?, ?, ?)',
      [id, name, age, course],
    );

    return res.status(200);
  } catch (err) {
    console.error('Error:', err);
    return res.status(500);
  }
});

router.delete('/deletePerson/:id', (req, res) => {
  try {
    const { id } = req.params;

    connection.query('DELETE FROM persons WHERE id = ?', [id]);

    return res.status(200);
  } catch (err) {
    console.error('Error:', err);
    return res.status(500);
  }
});

router.put('/updatePerson/:id', (req, res) => {
  try {
    const id = req.params.id;
    const { name, age, course } = req.body;

    connection.query(
      'UPDATE persons SET name = ?, age = ?, course = ? WHERE id = ?',
      [name, age, course, id],
    );

    return res.status(200);
  } catch (err) {
    console.error('Error:', err);
    return res.status(500);
  }
});

module.exports = router;
