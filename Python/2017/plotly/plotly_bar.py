import plotly
from plotly.graph_objs import *
from leo import *

data = [plotly.graph_objs.Bar(
			x = [str(i) for i in range(100)],
			y = [str(it_collatz(j)) for j in range(100)]
			)]

plotly.offline.plot(data)

def collatz_graph(n0, n1):
    data = [plotly.graph_objs.Bar(
			x = [str(i) for i in range(n0, n1)],
			y = [str(it_collatz(j)) for j in range(n0, n1)]
			)]
    plotly.offline.plot(data)
