document.addEventListener('DOMContentLoaded', function() {
    const taskInput = document.getElementById('task');
    const addTaskButton = document.getElementById('add-task');
    const taskList = document.getElementById('task-list');

    addTaskButton.addEventListener('click', function() {
        const taskText = taskInput.value.trim();

        if (taskText !== '') {
            const taskItem = document.createElement('li');
            taskItem.innerHTML = `
                <span>${taskText}</span>
                <button class="delete-button">Delete</button>
            `;

            taskList.appendChild(taskItem);

            taskInput.value = '';

            const deleteButton = taskItem.querySelector('.delete-button');
            deleteButton.addEventListener('click', function() {
                taskList.removeChild(taskItem);
            });
        }
    });
});
