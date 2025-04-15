#!/usr/bin/node

const request = require('request');

const movieId = process.argv[2];
const apiUrl = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

request(apiUrl, (err, res, body) => {
  if (err) return;

  const characters = JSON.parse(body).characters;

  const fetchCharacter = (index) => {
    if (index >= characters.length) return;

    request(characters[index], (charErr, charRes, charBody) => {
      if (charErr) return;
      console.log(JSON.parse(charBody).name);
      fetchCharacter(index + 1);
    });
  };

  fetchCharacter(0);
});
