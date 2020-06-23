// wasm.config.js
module.exports = {
    emscripten_path: './../emsdk',
    inputfile: './src/cpp/hello_world.cpp',
    outputfile: './src/wasm/hello_world.js',
    flags: [
      '-s WASM=1',
      'no-indexjs',
      'no-html',
      'no-server'
    ],
  };