// Globals are like MSG. They make everything taste better.
var g_start_x = null;
var g_start_y = null;

var Module = {
    // The WASM Module stuffs aren't available immediately because there's considerable
    // initialization to load WASM.
    onRuntimeInitialized: init,
    canvas: null,
    rectinator: null,
    rectangles: [],
};

function init() {
    Module.canvas = document.getElementById("canvas");
    Module.rectinator = new Module.Rectinator(Module.canvas.width, Module.canvas.height);
    Module.canvas.onmousedown = function (e) {
        g_start_x = e.clientX - Module.canvas.offsetLeft;
        g_start_y = e.clientY - Module.canvas.offsetTop;
        console.log("mouse down: (" + g_start_x + ", " + g_start_y + ")");
    };

    Module.canvas.onmouseup = function (e) {
        let end_x = e.clientX - Module.canvas.offsetLeft;
        let end_y = e.clientY - Module.canvas.offsetTop;
        console.log("mouse up: (" + end_x + ", " + end_y + ")");

        let min_x = Math.min(g_start_x, end_x);
        let min_y = Math.min(g_start_y, end_y);
        let max_x = Math.max(g_start_x, end_x);
        let max_y = Math.max(g_start_y, end_y);

        let width = max_x - min_x;
        let height = max_y - min_y;

        if (width < 3 && height < 3) {
            let rectangle = Module.rectinator.select(end_x, end_y);
            if (rectangle) {
                console.log("Selected rectangle!");
                let selected = "green";
                let deselected = "red";
                for (const rect of Module.rectangles) {
                    draw_rectangle(rect, deselected);
                }
                draw_rectangle(rectangle, selected);
            }
        } else {
            let rectangle = Module.rectinator.create(min_x, min_y, max_x, max_y);
            Module.rectangles.push(rectangle);
            let color = "red";
            draw_rectangle(rectangle, color);
        }
    };
}

function draw_rectangle(rect, color) {
    const ctx = Module.canvas.getContext("2d");
    ctx.fillStyle = color;
    let dimensions = array_from_vec(rect.dimensions());
    ctx.fillRect(...dimensions);
}

function array_from_vec(v) {
    var a = [];
    for (var i = 0; i < v.size(); i++) {
        a.push(v.get(i));
    }
    return a;
}
