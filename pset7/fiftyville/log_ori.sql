-- Keep a log of any SQL queries you execute as you solve the mystery.
-- The theft took place on July 28, 2020 and took place on Chamberlin Street
-- Find out who the thief is, what city they escaped to and their accomplice.


-- 1. Find crime scene report
SELECT description FROM crime_scene_reports WHERE month = 7 AND day = 28 AND street = "Chamberlin Street";
	-- Output:
	/* Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse. Interviews were conducted today with three witnesses who were present at the time — each of their interview transcripts mentions the courthouse. */

-- 2. Find courthouse security logs for that day. The logs contain information on license plate numbers and whether they were recorded from the entrace or exit of courthouse.
SELECT activity, license_plate FROM courthouse_security_logs WHERE month = 7 AND day = 28;
	-- Output:
	/* Returned 74 results. Need to be more specific with time. The duck took place at 10:15am, so I will query for before that time. */

-- 3. Query for time before 10:15am;
SELECT hour, minute, activity, license_plate FROM courthouse_security_logs WHERE month = 7 AND day = 28 AND hour <= 10;
	-- Output:
	/* Returned 53 license plate results.
	I can use these 53 results to see if I can dig up people names. */

-- 4. Query for people names for the result from query 3.
SELECT name FROM people WHERE license_plate IN (
	SELECT license_plate FROM courthouse_security_logs WHERE month = 7 AND day = 28 AND hour <= 10);
	--Output:
	/* Returned 29 names. */

-- 5. Query for interviews from that day.
SELECT name, transcript FROM interviews WHERE month = 7 AND day = 28;
	--Output:
	/* There were 6 outputs in total, but only 3 relevant interviews from the 3 witnesses of the crime.

	Ruth|Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away. If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.

	Eugene|I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at the courthouse, I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.

	Raymond|As the thief was leaving the courthouse, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. */

-- 6. Query license plate numbers that left the courthouse within 10 minutes of the theft which would be 10:05 to 10:25.
SELECT license_plate FROM courthouse_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute >= 5 AND minute <= 25;
	-- Output:
	Returned 10 results. I can use these numbers to query a name.

-- 7. Query names of people whom the license plates from Query 6 belongs to.
SELECT name FROM people WHERE license_plate IN (
SELECT license_plate FROM courthouse_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute >= 5 AND minute <= 25);
	-- Output: 
	/* Patrick
	Amber
	Brandon
	Elizabeth
	Roger
	Danielle
	Russell
	Evelyn
	Ernest
	Sophia
	These are my initial list of suspects. */

-- 8. Follow up on Eugene's interview for the time he arrived at the courthouse. Need to use his license plate number.
SELECT license_plate FROM people WHERE name = "Eugene";
	-- Output:
	/* 47592FJ */

-- 9. Continue follow up on Query 8. Find out what time Eugene arrived at the courthouse.
SELECT hour, minute FROM courthouse_security_logs
WHERE month = 7 AND day = 28 AND license_plate = "47592FJ";
	-- Output:
	/* No results */

-- 10. Find the person make atm withdrawal transactions before 10:15 on that day.
SELECT name FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE year = 2020 AND month = 7 AND day = 28 AND atm_location = "Fifer Street" AND transaction_type = "withdraw";
	-- Output:
	/* Returned 65 results. Results include bank_account numbers and amounts. */

-- 11. Find out the first flight that left Fiftyville.
	-- First find out Fiftyville's airport_id
	SELECT id FROM airports WHERE full_name like "%Fiftyville%";
		-- Output:
		/* 8 */

	-- Find out the flight ID of the first flight.
	SELECT id FROM flights WHERE month = 7 AND day = 29 AND origin_airport_id = (SELECT id FROM airports WHERE full_name like "%Fiftyville%") ORDER BY hour ASC, minute ASC LIMIT 1;
		-- Output:
		/* 36 */

	-- Find out list of passport of passengers from flight id 36.
	SELECT passport_number FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE month = 7 AND day = 29 AND origin_airport_id = (SELECT id FROM airports WHERE full_name like "%Fiftyville%") ORDER BY hour ASC, minute ASC LIMIT 1);
		-- Output:
		/* Returned 8 results that can be used to identify a name.*/


	-- Find out the destination of the first flight.
	SELECT full_name FROM airports WHERE id = (
	SELECT destination_airport_id FROM flights WHERE month = 7 AND day = 29 AND origin_airport_id = (SELECT id FROM airports WHERE full_name like "%Fiftyville%") ORDER BY hour ASC, minute ASC LIMIT 1);
	-- Output:
	/* Heathrow Airport */

-- 12. Identify the phone numbers that sent and received calls on the day of the theft where in the phone call was less than 60 seconds.
SELECT caller FROM phone_calls WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60;
	-- Output:
	/* Returned 9 results that can be used to identify a name */