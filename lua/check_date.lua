-- to check if a date in format defined in rfc 3339
--
local datetime_strings = {"2022-12-21T13:45:00-05:00",
        "2022-12-21T13:45:00Z", "2022-12-21T13:45:00.123456+01:00"}
function checkDate(datetime_string)
    local pattern    = "(%d+)-(%d+)-(%d+)T(%d+):(%d+):(%d+)([(%.%d+)])([%+%-])(%d+):(%d+)Z"
    -- local pattern = "(%d+)-(%d+)-(%d+)T(%d+):(%d+):(%d+)([%+%-])(%d+):(%d+)"
    local year, month, day, hour, minute, second, offset_sign, offset_hours, offset_minutes = datetime_string:match(pattern)

    if year and month and day and hour and minute and second and offset_sign and offset_hours and offset_minutes then
      -- Datetime string is in the proper format
      print("Date", datetime_string ,"is in proper format",offset_sign)
    else
      -- Datetime string is not in the proper format
      print("Date", datetime_string ,"is Not in proper format",offset_sign)
    end
end

function is_valid_datetime(datetime_string)
    print("Checking",datetime_string)
  -- local pattern = "(%d+)-(%d+)-(%d+)T(%d+):(%d+):(%d+)(%.%d*)([%+%-])(%d+):(%d+)"
  local pattern =  "(%d+)-(%d+)-(%d+)T(%d+):(%d+):(%d+)([%-%+]%d+:%d+)"
  -- local pattern = "(%d+)-(%d+)-(%d+)T(%d+):(%d+):(%d+)((%.%d*)|([%+%-]%d+:%d+))"--([%+%-]%d+:%d+)" --([%+%-])(%d+):(%d+)"
  local year, month, day, hour, minute, second, fraction, offset_sign, offset_hours, offset_minutes = datetime_string:match(pattern)

  if year and month and day and hour and minute and second and (offset_sign or offset_sign == "Z" ) then
      
      print("Date", datetime_string ,"is in proper format",fraction)
      print("Date", datetime_string ,"is Not in proper format",fraction)
      print("Year:",year)
      print("month:",month)
      print("day:",day)
      print("hour:",hour)
      print("minute:",minute)
      print("second:",second)
      print("fraction:",fraction)
      print("offset_sign:",offset_sign)
    return true
  else
      -- print(year,month,day..'T'..hour..":"..(minute or 'nil')..':'..(second or 'nil'))
      print("Date", datetime_string ,"is Not in proper format",fraction)
      print("Year:",year)
      print("month:",month)
      print("day:",day)
      print("hour:",hour)
      print("minute:",minute)
      print("second:",second)
      print("fraction:",fraction)
      print("offset_sign:",offset_sign)
    return false
  end
end

for _,date in ipairs(datetime_strings) do 
      is_valid_datetime(date) 
end
-- for _,date in ipairs(datetime_strings) do 
--       print(date) 
-- end
