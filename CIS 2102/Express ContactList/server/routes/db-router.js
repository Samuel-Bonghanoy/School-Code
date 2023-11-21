const express = require('express');

const connection = require('../db');

const router = express.Router({ mergeParams: true });

router.route('/').get('/createdb', (req, res) => {
  connection.query(`CREATE DATABASE ${process.env.DATABASE}`, (err, result) => {
    if (err) console.log(err);

    res.send(result);
  });
});

module.exports = router;
