#!/usr/bin/node
// Script that prints all characters of a Star Wars movie using the Star Wars API

const request = require('request');

// Get the Movie ID from the command line argument
const movieId = process.argv[2];

// Check if Movie ID is provided
if (!movieId || isNaN(parseInt(movieId))) {
  console.error('Usage: ./0-starwars_characters.js <Movie ID>');
  process.exit(1); // Exit with an error code
}

// Construct the API URL for the specific film
const filmUrl = `https://swapi.dev/api/films/${movieId}/`;

// Options for the request, disabling strict SSL checking
const requestOptions = {
  url: filmUrl, // Cannot use shorthand here as key 'url' != variable 'filmUrl'
  strictSSL: false
};

// First request: Get the film details
request(requestOptions, (error, response, body) => { // Pass options object
  if (error) {
    console.error('Error fetching film data:', error);
    process.exit(1);
  }

  // Check for successful response status code
  if (response.statusCode !== 200) {
    console.error(`Error: Received status code ${response.statusCode} for film URL ${filmUrl}`);
    process.exit(1);
  }

  try {
    // Parse the JSON response body
    const filmData = JSON.parse(body);
    const characterUrls = filmData.characters;

    if (!characterUrls || characterUrls.length === 0) {
      // No characters found for this film
      process.exit(0); // Exit cleanly
    }

    // Array to hold character names in the correct order
    const characterNames = new Array(characterUrls.length);
    // Counter for completed character requests
    let charactersProcessed = 0;
    const totalCharacters = characterUrls.length;

    // Function to fetch and store character name
    const fetchCharacter = (url, index) => {
      const charRequestOptions = { // Options for character requests
        url, // Fixed: Use object property shorthand here
        strictSSL: false
      };
      request(charRequestOptions, (charError, charResponse, charBody) => { // Pass options object
        if (!charError && charResponse.statusCode === 200) {
          try {
            const characterData = JSON.parse(charBody);
            // Store the name at the correct index
            characterNames[index] = characterData.name;
          } catch (parseErr) {
            console.error(`Error parsing character data from ${url}:`, parseErr);
            // Optionally store an error marker: characterNames[index] = 'Error';
          }
        } else {
          console.error(`Error fetching character ${url}:`, charError || `Status Code ${charResponse ? charResponse.statusCode : 'N/A'}`);
          // Optionally store an error marker: characterNames[index] = 'Error';
        }

        // Increment the counter after each request finishes (success or fail)
        charactersProcessed++;

        // If all character requests have finished
        if (charactersProcessed === totalCharacters) {
          // Print the names in order
          characterNames.forEach(name => {
            if (name) { // Avoid printing undefined if an error occurred without storing a marker
              console.log(name);
            }
          });
        }
      });
    };

    // Iterate through character URLs and start fetching each one
    // Use forEach with index to maintain the original order
    characterUrls.forEach((url, index) => {
      fetchCharacter(url, index);
    });
  } catch (parseError) {
    console.error('Error parsing film JSON response:', parseError);
    process.exit(1);
  }
}); // <-- Make sure there is a newline character after this line in the file
