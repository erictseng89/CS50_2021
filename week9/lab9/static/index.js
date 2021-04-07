
function loadDates() {
	const days29 = 2;
	const days30 = [4, 6, 9, 11];
	let dates = `<option value="day" seleceted disabled>Day</option>`;
	let month = parseInt(document.getElementById('month').value);
	console.log(dates)
	let printer = month == days29 ? 29 : days30.includes(month) ? 30 : 31;
	for (let i = 1; i <= printer; i++) {
		dates += `<option value="${i}">${i}</option>`
	}
	console.log(dates);
	document.getElementById("day").innerHTML = dates;
}


document.getElementById("month").addEventListener('change', loadDates);