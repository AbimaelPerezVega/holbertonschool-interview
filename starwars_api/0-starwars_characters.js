#!/usr/bin/node

const request = require('request');

const movieId = process.argv[2];
const url = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

request(url, (err, response, body) => {
  if (err) return;

  const characters = JSON.parse(body).characters;

  const printCharacter = (index) => {
    if (index >= characters.length) return;

    request(characters[index], (err2, res2, body2) => {
      if (err2) return;
      console.log(JSON.parse(body2).name);
      printCharacter(index + 1);
    });
  };
w
  printCharacter(0);
});
