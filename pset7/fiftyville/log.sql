-- Theif is
SELECT name FROM people 
WHERE license_plate IN (
SELECT license_plate FROM courthouse_security_logs 
WHERE month = 7 AND day = 28 AND hour = 10 AND minute >= 5 AND minute <= 25)
INTERSECT
SELECT name FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE year = 2020 AND month = 7 AND day = 28 AND atm_location = "Fifer Street" AND transaction_type = "withdraw"
INTERSECT
SELECT name FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
WHERE flight_id = (
SELECT id FROM flights 
WHERE month = 7 AND day = 29 AND origin_airport_id = (
SELECT id FROM airports WHERE full_name LIKE "%Fiftyville%") 
ORDER BY hour ASC, minute ASC LIMIT 1)
INTERSECT
SELECT name FROM people
JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60;

-- Escaped to
SELECT city FROM airports 
WHERE id = (
SELECT destination_airport_id FROM flights WHERE month = 7 AND day = 29 AND origin_airport_id = (
SELECT id FROM airports 
WHERE full_name like "%Fiftyville%") 
ORDER BY hour ASC, minute ASC LIMIT 1);

-- Accomplice is
SELECT name FROM people
JOIN phone_calls ON people.phone_number = phone_calls.receiver
WHERE caller = (
SELECT phone_number FROM people 
WHERE license_plate IN (
SELECT license_plate FROM courthouse_security_logs 
WHERE month = 7 AND day = 28 AND hour = 10 AND minute >= 5 AND minute <= 25)
INTERSECT
SELECT phone_number FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE year = 2020 AND month = 7 AND day = 28 AND atm_location = "Fifer Street" AND transaction_type = "withdraw"
INTERSECT
SELECT phone_number FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
WHERE flight_id = (
SELECT id FROM flights 
WHERE month = 7 AND day = 29 AND origin_airport_id = (
SELECT id FROM airports WHERE full_name LIKE "%Fiftyville%") 
ORDER BY hour ASC, minute ASC LIMIT 1)
INTERSECT
SELECT phone_number FROM people
JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60)
AND year = 2020 AND month = 7 AND day = 28 AND duration < 60;