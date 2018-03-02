import plotly
from plotly.graph_objs import *
from leo import *

data = [plotly.graph_objs.Bar(
			x = [str(i) for i in range(100)],
			y = [str(it_collatz(j)) for j in range(100)]
			)]

plotly.offline.plot(data)
