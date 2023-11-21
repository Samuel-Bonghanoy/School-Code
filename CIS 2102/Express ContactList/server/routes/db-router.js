const express = require('express');

const connection = require('../db');

const router = express.Router({ mergeParams: true });

router.get('/createdb', (req, res) => {
  connection.query(`CREATE DATABASE ${process.env.DATABASE}`, (err, result) => {
    if (err) console.log(err);

    res.send(result);
  });
});

router.get('/createtable', (req, res) => {
  connection.query(
    `CREATE TABLE persons (
    id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(255) NOT NULL,
    age INT,
    course VARCHAR(100)
);`,
    (err, result) => {
      if (err) console.log(err);

      res.send(result);
    },
  );
});

router.post('/populate', (req, res) => {
  connection.query(
    `INSERT INTO persons (id, name, age, course)
    VALUES
        (1, 'Samule', 20, 'Computer Science'),
        (2, 'Mary sucks', 22, 'Mathematics'),
        (3, 'JDG >>>', 28, 'Physics');`,
    (err, result) => {
      if (err) console.log(err);

      res.send(result);
    },
  );
});

module.exports = router;
