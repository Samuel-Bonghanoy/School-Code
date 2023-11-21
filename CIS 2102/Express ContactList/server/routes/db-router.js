const express = require('express');

const connection = require('../db');

const router = express.Router({ mergeParams: true });

router.get('/createdb', (req, res) => {
  connection.query(`CREATE DATABASE ${process.env.DATABASE}`, (err, result) => {
    if (err) console.log(err);

    res.send(result);
  });

  connection.query(
    `CREATE TABLE persons (
    id INT PRIMARY KEY,
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

module.exports = router;
