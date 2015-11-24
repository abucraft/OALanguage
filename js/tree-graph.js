!function () {
	var d3 = require('./d3.min.js');
	var tree;
	var i = 0,
		duration = 750,
		root;
	var diagonal, svg;
	var treeId = "id_treeGraph";
	var containerId = "id_treeContain";
	var tokenAreaId = "id_tokenStream";
	function showToken(tokenStream){
		document.getElementById(tokenAreaId).innerHTML = tokenStream;
	}
	/*
	draw a parser tree in container
	*/
	function drawTree(rawText) {
		if (tree != null) {
			var treeGraph = document.getElementById(treeId);
			treeGraph.parentNode.removeChild(treeGraph);
		}
		var margin = { top: 20, right: 120, bottom: 20, left: 120 },
			width = 960 - margin.right - margin.left,
			height = 800 - margin.top - margin.bottom;

		var jsonobj = JSON.parse(rawText);
		if(jsonobj.error != null){
			alert(jsonobj.error);
			return ;
		}
		alert(JSON.stringify(jsonobj));
		tree = d3.layout.tree()
			.size([height, width]);

		diagonal = d3.svg.diagonal()
			.projection(function (d) { return [d.y, d.x]; });

		svg = d3.select('#'+containerId).append("svg")
			.attr("id", treeId)
			.attr("width", width + margin.right + margin.left)
			.attr("height", height + margin.top + margin.bottom)
			.append("g")
			.attr("transform", "translate(" + margin.left + "," + margin.top + ")");

		root = jsonobj;
		root.x0 = height / 2;
		root.y0 = 0;

		root.children.forEach(collapse);
		update(root);

		function collapse(d) {
			if (d.children) {
				d._children = d.children;
				d._children.forEach(collapse);
				d.children = null;
			}
		}
		function update(source) {

			// Compute the new tree layout.
			var nodes = tree.nodes(root).reverse(),
				links = tree.links(nodes);

			// Normalize for fixed-depth.
			nodes.forEach(function (d) { d.y = d.depth * 180; });

			// Update the nodes…
			var node = svg.selectAll("g.node")
				.data(nodes, function (d) { return d.id || (d.id = ++i); });

			// Enter any new nodes at the parent's previous position.
			var nodeEnter = node.enter().append("g")
				.attr("class", "node")
				.attr("transform", function (d) { return "translate(" + source.y0 + "," + source.x0 + ")"; })
				.on("click", click);

			nodeEnter.append("circle")
				.attr("r", 1e-6)
				.style("fill", function (d) { return d._children ? "lightsteelblue" : "#fff"; });

			nodeEnter.append("text")
				.attr("x", function (d) { return d.children || d._children ? -10 : 10; })
				.attr("dy", ".35em")
				.attr("text-anchor", function (d) { return d.children || d._children ? "end" : "start"; })
				.text(function (d) { return d.name; })
				.style("fill-opacity", 1e-6);

			// Transition nodes to their new position.
			var nodeUpdate = node.transition()
				.duration(duration)
				.attr("transform", function (d) { return "translate(" + d.y + "," + d.x + ")"; });

			nodeUpdate.select("circle")
				.attr("r", 6)
				.style("fill", function (d) { return d._children ? "lightsteelblue" : "#fff"; });

			nodeUpdate.select("text")
				.style("fill-opacity", 1);

			// Transition exiting nodes to the parent's new position.
			var nodeExit = node.exit().transition()
				.duration(duration)
				.attr("transform", function (d) { return "translate(" + source.y + "," + source.x + ")"; })
				.remove();

			nodeExit.select("circle")
				.attr("r", 1e-6);

			nodeExit.select("text")
				.style("fill-opacity", 1e-6);

			// Update the links…
			var link = svg.selectAll("path.link")
				.data(links, function (d) { return d.target.id; });

			// Enter any new links at the parent's previous position.
			link.enter().insert("path", "g")
				.attr("class", "link")
				.attr("d", function (d) {
					var o = { x: source.x0, y: source.y0 };
					return diagonal({ source: o, target: o });
				});

			// Transition links to their new position.
			link.transition()
				.duration(duration)
				.attr("d", diagonal);

			// Transition exiting nodes to the parent's new position.
			link.exit().transition()
				.duration(duration)
				.attr("d", function (d) {
					var o = { x: source.x, y: source.y };
					return diagonal({ source: o, target: o });
				})
				.remove();

			// Stash the old positions for transition.
			nodes.forEach(function (d) {
				d.x0 = d.x;
				d.y0 = d.y;
			});
		}

		// Toggle children on click.
		function click(d) {
			if (d.children) {
				d._children = d.children;
				d.children = null;
			} else {
				d.children = d._children;
				d._children = null;
			}
			update(d);
		}

		d3.select(self.frameElement).style("height", "800px");
		
	}
	var treeGraph = {};
	treeGraph.drawTree = drawTree;
	treeGraph.showToken = showToken;
	module.exports = treeGraph;
} ();