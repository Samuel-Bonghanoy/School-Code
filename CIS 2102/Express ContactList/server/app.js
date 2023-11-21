const express = require('express');

const app = express();

const dbRouter = require('./routes/db-router');

require('dotenv').config();

app.use(express.json());
app.use(require('cors')());

app.use('/', dbRouter);

app.listen(process.env.PORT, () => {
  console.log(`Server is now listening on port ${process.env.PORT}`);
});
