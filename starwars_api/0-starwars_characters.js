#!/usr/bin/node

const request = require('request');
const movieId = process.argv[2];

if (!movieId) {
  console.error('Please provide a movie ID');
  process.exit(1);
}

const filmUrl = `https://swapi-api.hbtn.io/api/films/${movieId}`;

// First, get the film data to retrieve the characters URLs
request(filmUrl, (error, response, body) => {
  if (error) {
    console.error(error);
    return;
  }

  if (response.statusCode !== 200) {
    console.error(`Error: Status code ${response.statusCode}`);
    return;
  }

  const film = JSON.parse(body);
  const charactersUrls = film.characters;

  // Function to get character data using Promises
  const getCharacter = (url) => {
    return new Promise((resolve, reject) => {
      request(url, (error, response, body) => {
        if (error) {
          reject(error);
          return;
        }
        if (response.statusCode !== 200) {
          reject(`Error: Status code ${response.statusCode}`);
          return;
        }
        resolve(JSON.parse(body));
      });
    });
  };

  // Use async/await to fetch and print characters in order
  const printCharacters = async () => {
    try {
      // Process the characters in their original order
      for (const url of charactersUrls) {
        const character = await getCharacter(url);
        console.log(character.name);
      }
    } catch (err) {
      console.error(err);
    }
  };

  printCharacters();
});