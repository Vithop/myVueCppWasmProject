<template>
  <div class="hello">
    <h1>{{ msg }}</h1>
    <p>
      For a guide and recipes on how to configure / customize this project,<br>
      check out the
      <a href="https://cli.vuejs.org" target="_blank" rel="noopener">vue-cli documentation</a>.
    </p>
    <h3>Installed CLI Plugins</h3>
    <ul>
      <li><a href="https://github.com/vuejs/vue-cli/tree/dev/packages/%40vue/cli-plugin-babel" target="_blank" rel="noopener">babel</a></li>
      <li><a href="https://github.com/vuejs/vue-cli/tree/dev/packages/%40vue/cli-plugin-eslint" target="_blank" rel="noopener">eslint</a></li>
    </ul>
    <h3>Essential Links</h3>
    <ul>
      <li><a href="https://vuejs.org" target="_blank" rel="noopener">Core Docs</a></li>
      <li><a href="https://forum.vuejs.org" target="_blank" rel="noopener">Forum</a></li>
      <li><a href="https://chat.vuejs.org" target="_blank" rel="noopener">Community Chat</a></li>
      <li><a href="https://twitter.com/vuejs" target="_blank" rel="noopener">Twitter</a></li>
      <li><a href="https://news.vuejs.org" target="_blank" rel="noopener">News</a></li>
    </ul>
    <h3>Ecosystem</h3>
    <ul>
      <li><a href="https://router.vuejs.org" target="_blank" rel="noopener">vue-router</a></li>
      <li><a href="https://vuex.vuejs.org" target="_blank" rel="noopener">vuex</a></li>
      <li><a href="https://github.com/vuejs/vue-devtools#vue-devtools" target="_blank" rel="noopener">vue-devtools</a></li>
      <li><a href="https://vue-loader.vuejs.org" target="_blank" rel="noopener">vue-loader</a></li>
      <li><a href="https://github.com/vuejs/awesome-vue" target="_blank" rel="noopener">awesome-vue</a></li>
    </ul>
    <p button @click="callSqrt(sumNum)"> Sqrt!</p>
    <p> Result: {{result}}</p>    
    <p button @click="callLog(sumNum)"> Log!</p>
    <p> Log Result: {{logResult}}</p>  
    <p button @click="callLerp(sumNum, result, logResult)"> Lerp!</p>
    <p> Sum Numb: {{lerpResult}}</p>
    <p button @click="addOne"> Add One!</p>
    <p> Sum Numb: {{sumNum}}</p>
  </div>
</template>

<script>
//Plain emscripten Module for C functions
import Module from '../../js/function';
//Emscripten C++ Module binded using Embind
import lerpModule from '../../js/lerp'

//Instead of using a global instance for the function Module here we implement a local instance of the module
let lerpInstance = null;


export default {
  name: 'HelloWorld',
  props: {
    msg: String
  },
  data() {
    return {
      result:null,
      logResult:1,
      lerpResult:0,
      sumNum:1
    }
  },
  beforeCreate(){
    //Before using our wasm modules we must wait for the runtime to be initialized before we can use it
    if(this.$globalModule === null){
      new Module().then(myModule =>{
        this.$globalModule = myModule;
      })
    }
    if(lerpInstance === null){
      new lerpModule().then(myLerp =>{
        lerpInstance = myLerp;
      })
    }
  },
  methods: {
    callSqrt(a){
      this.result = this.$globalModule._int_sqrt(a);
    },
    callLog(a){
      this.logResult = this.$globalModule._my_log(a);
    },
    callLerp(a,b,c){
      this.lerpResult = lerpInstance.lerp(a,b,c);
    },
    addOne(){
      this.sumNum++;
    }
  }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
h3 {
  margin: 40px 0 0;
}
ul {
  list-style-type: none;
  padding: 0;
}
li {
  display: inline-block;
  margin: 0 10px;
}
a {
  color: #42b983;
}
</style>
