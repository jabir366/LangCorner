-- local datetime_string = "2022-08-27T14:34:54.507834+03:00"
local datetime_string = "2022-12-21T13:45:00-05:00"

-- Extract the year, month, day, hour, minute, second, and fraction from the datetime string
local pattern = "(%d+)-(%d+)-(%d+)T(%d+):(%d+):(%d+)([%+%-]%d+:%d+)"
local year, month, day, hour, minute, second, offset = datetime_string:match(pattern)

-- Convert the year, month, day, hour, minute, and second to a Unix timestamp
local timestamp = os.time({year = year, month = month, day = day, hour = hour, min = minute, sec = second})
-- Convert the Unix timestamp to a UTC datetime string
local utc_datetime_string = os.date("%Y-%m-%dT%H:%M:%SZ", timestamp)

print(datetime_string)  -- Outputs: "2022-08-27T11:34:54Z"
print(offset)  -- Outputs: "2022-08-27T11:34:54Z"
print(utc_datetime_string)  -- Outputs: "2022-08-27T11:34:54Z"


