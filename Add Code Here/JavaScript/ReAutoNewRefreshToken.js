// axios.js
import axios from 'axios';

const instance = axios.create({
	baseURL: 'https://api.example.com',
});

let isRefreshing = false;
let requestsQueue = [];

instance.interceptors.request.use((config) => {
	const accessToken = localStorage.getItem('access_token');
	if (accessToken) {
		config.headers.Authorization = `Bearer ${accessToken}`;
	}
	return config;
});

instance.interceptors.response.use(
	(response) => response,
	(error) => {
		const originalRequest = error.config;

		if (error.response.status === 401 && !originalRequest._retry) {
			if (isRefreshing) {
				// Wait for the new access token and then retry the original request
				return new Promise((resolve) => {
					requestsQueue.push((token) => {
						originalRequest.headers.Authorization = `Bearer ${token}`;
						resolve(axios(originalRequest));
					});
				});
			}

			// Set the flag to indicate that we're refreshing the token
			isRefreshing = true;

			// Request a new access token using the refresh token
			return axios
				.post('/api/refresh-token', { refreshToken: localStorage.getItem('refresh_token') })
				.then((response) => {
					// Update localStorage with new access token
					localStorage.setItem('access_token', response.data.accessToken);
					// Retry the original request with the new access token
					originalRequest.headers.Authorization = `Bearer ${response.data.accessToken}`;
					// Clear the flag and flush the queue
					isRefreshing = false;
					requestsQueue.forEach((callback) => callback(response.data.accessToken));
					requestsQueue = [];
					return axios(originalRequest);
				})
				.catch((error) => {
					// Handle refresh token request error (e.g., redirect to login page)
					// ...
					throw error;
				});
		}
		return Promise.reject(error);
	}
);

export default instance;
