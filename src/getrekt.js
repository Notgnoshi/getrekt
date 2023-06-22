// Globals are like MSG. They make everything taste better.
var g_start_x = null;
var g_start_y = null;

var Module = {
    // The WASM Module stuffs aren't available immediately because there's considerable
    // initialization to load WASM.
    onRuntimeInitialized: init,
};

function init() {
    let canvas = document.getElementById("canvas");
    canvas.onmousedown = function (e) {
        g_start_x = e.clientX - canvas.offsetLeft;
        g_start_y = e.clientY - canvas.offsetTop;

        console.log("mouse down: (" + g_start_x + ", " + g_start_y + ")");
    };

    canvas.onmouseup = function (e) {
        let end_x = e.clientX - canvas.offsetLeft;
        let end_y = e.clientY - canvas.offsetTop;
        console.log("mouse up: (" + end_x + ", " + end_y + ")");

        let min_x = Math.min(g_start_x, end_x);
        let min_y = Math.min(g_start_y, end_y);
        let max_x = Math.max(g_start_x, end_x);
        let max_y = Math.max(g_start_y, end_y);

        let width = max_x - min_x;
        let height = max_y - min_y;

        let rectangle = new Module.Rectangle(min_x, min_y, width, height);

        handle_rectangle(rectangle);
    };
}

function handle_rectangle(rect) {
    const canvas = document.getElementById("canvas");
    if (canvas.getContext) {
        const ctx = canvas.getContext("2d");
        ctx.fillStyle = "rgb(200, 0, 0)";
        let dimensions = array_from_vec(rect.dimensions());
        console.log("Drawing dimensions: " + dimensions);
        ctx.fillRect(...dimensions);
    }
    // Unless it's a smart pointer you have to manually delete it
    rect.delete();
}

function array_from_vec(v) {
    var a = [];
    for (var i = 0; i < v.size(); i++) {
        a.push(v.get(i));
    }
    return a;
}
