let app=Vue.createApp({
    data(){return{
        product:'Cappello',
        description:'Cappello di lana',
        image:'.assets/grigio.jpg',
        disp:9,
        onSale:true,
        details:[
            {text:'Lana a maglia'},
            {text:'Pompon tipo raccoon'},
            {text:'Felpato foderato'}
        ],
        variants:[
            {id:2241, color:"grigio", image:'assets/grigio.jpg', htmlColor:'lightgrey'},
            {id:2242, color:"nero", image:'assets/nero.jpg', htmlColor:'black'},
            {id:2243, color:"beige", image:'assets/beige.jpg', htmlColor:'beige'}
        ],
        cart:0
    }},
    methods:{
        addToCart:function(){
            this.disp--;
            this.cart++;
        },
        updateImage:function(im){
            this.image=im;
        }
    }
});
app.mount('#app');