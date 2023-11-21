const express = require('express');

const app = express();

require('dotenv').config();

app.use(express.json());
app.use(require('cors')());

// app.use('/api/contacts', contactRouter);

app.listen(3000, () => {
  console.log('Server is now listening on port 3000');
});
