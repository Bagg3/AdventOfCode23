const fs = require("fs");

// Read the file asynchronously
fs.readFile("input.txt", "utf8", (err, data) => {
  if (err) {
    console.error("Error reading the file:", err);
    return;
  }

  // Split the data into an array of lines
  const lines = data.split("\n");

  let max;

  let sum = 0;

  lines.forEach((line) => {});
});

console.log("The sum is:", sum);

function check() {}
