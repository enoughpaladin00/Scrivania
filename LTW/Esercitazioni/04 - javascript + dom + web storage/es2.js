const divs = document.querySelectorAll("div");
divs.forEach(div => {
    div.addEventListener("mouseover", ()=> {
        div.style.backgroundColor = (div.style.backgroundColor === "initial" || div.style.backgroundColor === "") ? "red" : "initial";
    });
});

const c1s = document.querySelectorAll(".c1");
c1s.forEach(c1 => {
    c1.addEventListener("click", ()=> {
        c1.style.backgroundColor = "blue";
    })
    c1.addEventListener("dblclick", ()=> {
        c1.style.display = "none";
    })
})

const c2s = document.querySelectorAll(".c2");
c2s.forEach(c1 => {
    c2.addEventListener("mouseover", () => {
        c2.style.backgroundColor = "green";
    })
    c2.addEventListener("mouseout", () => {
        c2.style.backgroundColor = "inital"; 
    })
})

