const express = require('express');

const app = express();

const connection = require('./db');

require('dotenv').config();

app.use(express.json());
app.use(require('cors')());

app.get('/createdb', (req, res) => {
  connection.query(`CREATE DATABASE ${process.env.DATABASE}`, (err, result) => {
    if (err) console.log(err);

    res.send(result);
  });
});

app.listen(process.env.PORT, () => {
  console.log(`Server is now listening on port ${process.env.PORT}`);
});
