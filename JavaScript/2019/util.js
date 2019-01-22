Object.defineProperties(Array.prototype, {
	sum: {
		value: function() {
			return this.reduce( (acc, cv) => acc + cv);
		}
	},
	avg: {
		value: function() {
			return this.reduce( (acc, cv) => acc + cv) / this.length;
		}
	},
	remove: {
		value: function(key) {
			let F = this.find( V => V === key);
			if (F !== undefined)
			{
					this.splice(this.indexOf(F), 1);
					return true;
			}
			return false;
		}
	}
});

Object.defineProperties(Math, {
	randint: {
		value: function(min, max) {
			return Math.floor((Math.random() * (max - min + 1)) + min);
		}
	}
});