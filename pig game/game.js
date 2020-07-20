var score = [0,0];
var round_score = 0;
var active_player = 0;
var playing = true;

newgame();

function newgame() {
	score = [0,0];
	round_score = 0;
	active_player = 0;
	playing=true;
	document.querySelector('.dice').style.display = 'none';
	document.getElementById("current-0").textContent = 0;
	document.getElementById("score-0").textContent = 0;
	document.getElementById("current-1").textContent = 0;
	document.getElementById("score-1").textContent = 0;
	document.getElementById("name-0").textContent = 'Player 1';
	document.getElementById("name-1").textContent = 'Player 2';
	var player0_dom = document.querySelector('.player-0');
	var player1_dom = document.querySelector('.player-1');
	player0_dom.classList.remove('winner');
	player1_dom.classList.remove('winner');
	player0_dom.classList.remove('active');
	player1_dom.classList.remove('active');
	player0_dom.classList.add('active');
}

function next_player() {
	document.querySelector('.player-'+ active_player).classList.remove('active');
	active_player === 0 ? active_player = 1 : active_player = 0;
	document.querySelector('.player-' + active_player).classList.add('active');
	document.querySelector('.dice').style.display = 'none';
}

document.querySelector('.btn-roll').addEventListener('click', function() {
	if (playing) {
		var dice = Math.floor(Math.random()*6) + 1;

		var diceDOM = document.querySelector('.dice');
		diceDOM.style.display = 'block';
		diceDOM.src = 'dice-' + dice + '.png';

		if (dice===1) {
			round_score = 0;
			document.getElementById("current-" + active_player).textContent = round_score;
			next_player();
		}
		else {
			round_score += dice;
			document.getElementById("current-" + active_player).textContent = round_score;
		}
	}
});


document.querySelector('.btn-save').addEventListener('click', function() {
	score[active_player] += round_score;
	round_score = 0;
	document.getElementById("current-" + active_player).textContent = round_score;
	document.getElementById("score-" + active_player).textContent = score[active_player];

	if (score[active_player] > 99) {
		document.getElementById("name-" + active_player).textContent = "WINNER!";
		document.querySelector('.dice').style.display = 'none';
		document.querySelector('.player-' + active_player).classList.add('winner');
		document.querySelector('.player-' + active_player).classList.remove('active');
		playing = false;
	}
	else {
		next_player();
	}
});
document.querySelector('.btn-new').addEventListener('click', newgame);