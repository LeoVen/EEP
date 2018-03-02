import plotly

labels = ['Australia', 'Brazil', 'China', 'Colombia', 'India', 'Indonesia', 'Mexico', 'Pakistan', 'Thailand', 'USA']
values = [30.52, 736.11, 126.15, 36.51, 352.15, 28.6, 56.673, 62.83, 103.7, 27.6]
colors = ['#0d47a1', '#4caf50', '#d50000', '#ffd600', '#ff6d00', '#ffffff', '#f44336', '#1b5e20', '#4a148c', '#00bcd4']

trace = plotly.graph_objs.Pie(labels=labels, values=values,
				hoverinfo='label+percent', textinfo='value',
				textfont=dict(size=20),
				marker=dict(colors=colors))
plotly.offline.plot([trace])


#---------------------------Outro mais avançado

fig = {
  "data": [
    {
      "values": [16, 15, 12, 6, 5, 4, 42],
      "labels": [
        "US",
        "China",
        "European Union",
        "Russian Federation",
        "Brazil",
        "India",
        "Rest of World"
      ],
      "domain": {"x": [0, .48]},
      "name": "GHG Emissions",
      "hoverinfo":"label+percent+name",
      "hole": .4,
      "type": "pie"
    },     
    {
      "values": [27, 11, 25, 8, 1, 3, 25],
      "labels": [
        "US",
        "China",
        "European Union",
        "Russian Federation",
        "Brazil",
        "India",
        "Rest of World"
      ],
      "text":"CO2",
      "textposition":"inside",
      "domain": {"x": [.52, 1]},
      "name": "CO2 Emissions",
      "hoverinfo":"label+percent+name",
      "hole": .4,
      "type": "pie"
    }],
  "layout": {
        "title":"Global Emissions 1990-2011",
        "annotations": [
            {
                "font": {
                    "size": 20
                },
                "showarrow": False,
                "text": "GHG",
                "x": 0.20,
                "y": 0.5
            },
            {
                "font": {
                    "size": 20
                },
                "showarrow": False,
                "text": "CO2",
                "x": 0.8,
                "y": 0.5
            }
        ]
    }
}

plotly.offline.plot(fig)
