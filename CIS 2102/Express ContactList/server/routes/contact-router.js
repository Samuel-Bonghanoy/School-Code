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

    return res.status(200).json({ message: 'Person inserted successfully' });
  } catch (err) {
    console.error('Error:', err);
    return res.status(500).json({ error: 'Unsuccessful insert' });
  }
});

router.delete('/deletePerson/:id', (req, res) => {
  try {
    const { id } = req.params;

    connection.query('DELETE FROM persons WHERE id = ?', [id]);

    return res.status(200).json({ message: 'Person deleted successfully' });
  } catch (err) {
    console.error('Error:', err);
    return res.status(500).json({ error: 'Unsuccessful deletion' });
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

    return res.status(200).json({ message: 'Person updated successfully' });
  } catch (err) {
    console.error('Error:', err);
    return res.status(500).json({ error: 'Unsuccessful update' });
  }
});

module.exports = router;
