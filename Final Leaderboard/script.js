var teams = [];
    
    function createLeaderboard() {
      var teamCount = parseInt(document.getElementById("team-count").value);
      
      var leaderboardContainer = document.getElementById("leaderboard-container");
      leaderboardContainer.innerHTML = "";
      
      var table = document.createElement("table");
      var thead = document.createElement("thead");
      var tbody = document.createElement("tbody");
      
      var headerRow = document.createElement("tr");
      var rankHeader = document.createElement("th");
      rankHeader.textContent = "Rank";
      headerRow.appendChild(rankHeader);
      
      var teamHeader = document.createElement("th");
      teamHeader.textContent = "Team Name";
      headerRow.appendChild(teamHeader);
      
      var scoreHeader = document.createElement("th");
      scoreHeader.textContent = "Score";
      headerRow.appendChild(scoreHeader);
      
      thead.appendChild(headerRow);
      table.appendChild(thead);
      table.appendChild(tbody);
      leaderboardContainer.appendChild(table);
      
      teams = [];
      
      for (var i = 0; i < teamCount; i++) {
        var row = document.createElement("tr");
        
        var rankCell = document.createElement("td");
        rankCell.textContent = i + 1;
        row.appendChild(rankCell);
        
        var teamCell = document.createElement("td");
        var teamInput = document.createElement("input");
        teamInput.type = "text";
        teamInput.addEventListener("input", updateLeaderboard);
        teamCell.appendChild(teamInput);
        row.appendChild(teamCell);
        
        var scoreCell = document.createElement("td");
        var scoreInput = document.createElement("input");
        scoreInput.type = "number";
        scoreInput.min = "0";
        scoreInput.addEventListener("input", updateLeaderboard);
        scoreCell.appendChild(scoreInput);
        row.appendChild(scoreCell);
        
        tbody.appendChild(row);
        
        teams.push({
          teamCell: teamInput,
          scoreCell: scoreInput
        });
      }
    }
    
    function updateLeaderboard() {
      var tbody = document.querySelector("#leaderboard-container tbody");
      
      teams.sort(function(a, b) {
        return parseInt(b.scoreCell.value) - parseInt(a.scoreCell.value);
      });
      
      teams.forEach(function(team, index) {
        teamCell = team.teamCell;
        scoreCell = team.scoreCell;
        
        rankCell = tbody.rows[index].cells[0];
        rankCell.textContent = index + 1;
        
        scoreCell.value = scoreCell.value;
      });
    }
    
    function sortLeaderboard() {
      var tbody = document.querySelector("#leaderboard-container tbody");
      
      Array.from(tbody.rows).sort(function(a, b) {
        var scoreA = parseInt(a.cells[2].firstChild.value);
        var scoreB = parseInt(b.cells[2].firstChild.value);
        return scoreB - scoreA;
      }).forEach(function(row, index) {
        row.cells[0].textContent = index + 1;
        tbody.appendChild(row);
      });
    }