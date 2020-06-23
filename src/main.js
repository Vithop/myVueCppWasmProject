import Vue from 'vue'
import App from './App.vue'
import store from './store'
Vue.config.productionTip = false

//This creates a global instance of your c wasm module to be used by any module
Vue.prototype.$globalModule = null;


new Vue({
  store,
  render: h => h(App)
}).$mount('#app')
