
# myvuecppwasmproject

Basic Vue plus wasm project using emscripten

## Project setup
First got to [Emscripten getting started](https://emscripten.org/docs/getting_started/index.html) to set up emscripten to be able to compile c/cpp into wasm. 

To setup an Emscripten environment in a new terminal(cmd/powershell) cd into emsdk and run `.\emcmdprompt.bat`
Now cd back to the root of your run the following command to compile ur c/cpp to wasm
```
emcc src/cpp/function.c -o js/function.js -s EXTRA_EXPORTED_RUNTIME_METHODS=['ccall','cwrap'] -s EXPORTED_FUNCTIONS="['_int_sqrt', '_my_log']" -s ENVIRONMENT=web -s EXPORT_ES6=1 -s MODULARIZE=1 -s USE_ES6_IMPORT_META=0
``` 
Notice here the output file is set to js/function.js because the generated js from emscripten will be looking for it's wasm file inside a directory called js

The settings flag add to the compilation does the following 
Setting | Description
------------------------------ | ---------------------------------------
`EXTRA_EXPORTED_RUNTIME_METHODS=['ccall','cwrap']` | Tells the compiler the you want to use the runtime function `ccall` and `cwrap`
`EXPORTED_FUNCTIONS="['_int_sqrt', 'my_log']"` | Tells compiler which functions you want to be accessible from compiled code
`ENVIRONMENT=web` | Sets the js output to run on the web
`EXPORT_ES6=1` | Creates js to be imported using the `import` statement  
`MODULARIZE=1` | Wraps the generated code's `Module` object in a function
`USE_ES6_IMPORT_META=0` | Disables ES6 Module relative import feature to auto detect WASM Module path since vue does not support this

To find more emscripten compile settings go to [src/settings.js](https://github.com/emscripten-core/emscripten/blob/master/src/settings.js)


After compiling you can go ahead and install your node_modules and serve your project

```
npm install
```

### Compiles and hot-reloads for development
```
npm run serve
```

### Compiles and minifies for production
```
npm run build
```

### Lints and fixes files
```
npm run lint
```

### Customize configuration
See [Configuration Reference](https://cli.vuejs.org/config/).

### Research Links

https://dzone.com/articles/the-import-statement-with-an-emscripten-generated#:~:text=To%20tell%20Emscripten%20to%20create,Module%20object%20in%20a%20function. 

https://emscripten.org/docs/getting_started/index.html 
