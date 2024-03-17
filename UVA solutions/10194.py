def getPoints(a,b):
  if(a > b):
    return 3
  if(a == b):
    return 1
  return 0

def cmp(team):
  return (
      -team["points"], 
      -team["wins"], 
      -team["goalDif"], 
      -team["goalsScored"], 
      +team["games"], 
      team["name"].lower())

n = int(input())
for tc in range(n):
  if(tc != 0): print("")
  tournament = input()
  nteams = int(input())
  teams = {}
  for t in range(nteams):
    teamName = input()
    teams[teamName] = {
      "name": teamName,
      "points": 0,
      "games": 0,
      "wins": 0,
      "ties": 0,
      "losses": 0,
      "goalDif": 0,
      "goalsScored": 0,
      "goalsAgainst" :0
    }
  ngames = int(input())
  for g in range(ngames):
    game = input()
    [teamA, scoreA] = game.split("@")[0].split("#")
    [scoreB, teamB] = game.split("@")[1].split("#")
    scoreA = int(scoreA)
    scoreB = int(scoreB)

    teams[teamA]["points"] += getPoints(scoreA, scoreB)
    teams[teamA]["games"] += 1
    teams[teamA]["wins"] += 1 if scoreA > scoreB else 0
    teams[teamA]["ties"] += 1 if scoreA == scoreB else 0
    teams[teamA]["losses"] += 1 if scoreA < scoreB else 0
    teams[teamA]["goalsScored"] += scoreA
    teams[teamA]["goalsAgainst"] += scoreB

    teams[teamB]["points"] += getPoints(scoreB, scoreA)
    teams[teamB]["games"] += 1
    teams[teamB]["wins"] += 1 if scoreB > scoreA else 0
    teams[teamB]["ties"] += 1 if scoreB == scoreA else 0
    teams[teamB]["losses"] += 1 if scoreB < scoreA else 0
    teams[teamB]["goalsScored"] += scoreB
    teams[teamB]["goalsAgainst"] += scoreA

  teamsList = []
  for key,val in teams.items():
    teams[key]["goalDif"] = teams[key]["goalsScored"] - teams[key]["goalsAgainst"] 
    teamsList.append(val)
  
  teamsList = sorted(teamsList, key=cmp)
  
  print(tournament)
  rank = 0
  for team in teamsList:
    rank += 1
    n = team["name"]
    b = team["points"]
    c = team["games"]
    d = team["wins"]
    e = team["ties"]
    f = team["losses"]
    g = team["goalDif"]
    h = team["goalsScored"]
    i = team["goalsAgainst"]
    print("%d) %s %sp, %sg (%s-%s-%s), %sgd (%s-%s)" % (rank,n,b,c,d,e,f,g,h,i) )