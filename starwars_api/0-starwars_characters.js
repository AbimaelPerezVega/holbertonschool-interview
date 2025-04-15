#!/usr/bin/node

const request = require('request');

if (process.argv.length < 3) {
  console.error('Usage: ./0-starwars_characters.js <Movie_ID>');
  process.exit(1);
}

const movieId = process.argv[2];
const filmUrl = `https://swapi-api.alx-tools.com/api/films/${movieId}/`;

request(filmUrl, async (err, res, body) => {
  if (err) return console.error(err);

  const film = JSON.parse(body);
  const characters = film.characters;

  for (const url of characters) {
    await new Promise((resolve, reject) => {
      request(url, (err, res, body) => {
        if (err) return reject(err);
        const character = JSON.parse(body);
        console.log(character.name);
        resolve();
      });
    });
  }
});
